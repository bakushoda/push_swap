*This project has been created as part of the 42 curriculum by bshoda, harnakaj.*

# Description

`push_swap` sorts integers with two stacks and the operations required by the subject.
The first argument is the top of stack A. The mandatory strategy selectors, disorder
measurement, and benchmark mode are included; the bonus checker is intentionally not.

# Instructions

Build with `make`, then run:

```sh
./push_swap 3 2 1
./push_swap --simple 3 2 1
./push_swap --medium 3 2 1
./push_swap --complex 3 2 1
./push_swap --adaptive --bench 3 2 1
```

Operations go to stdout. `--bench` writes statistics to stderr.

# Algorithms

All complexity classes below count emitted Push_swap instructions, as required by
the subject. They do not describe C execution time: disorder measurement and rank
compression take O(n²) comparisons, and array-based pushes/rotations take O(n) CPU
work each. Rank compression replaces each integer with the number of smaller input
values, preserving all ordering comparisons and supporting negative integers.

All selectors share constant-size cases: sorted inputs emit nothing, two or three
elements use direct cases, and four or five elements extract the smallest ranks to B,
sort the remaining three, then restore B. This does not change asymptotic bounds.
The benchmark reports the selected strategy, including for these small cases.

## Simple: O(n²)

Find A's minimum, rotate it to the top using the shorter direction, and push it to B.
Repeat until one element remains, then restore B to A. B has its largest extracted
value at the top, so restoration produces ascending A. For each remaining size k,
at most floor(k/2) rotations and one push are emitted. Summing over k and adding
the restoration pushes gives O(n²) operations. Auxiliary storage is O(n).

## Medium: O(n sqrt(n))

Use ranks 0 through n-1 and a moving window of width w = ceil(sqrt(n)) + 1.
After p pushes, a rank below p+w can be pushed; other ranks rotate in A. Values
at most p are pushed and rotated to B's bottom; other accepted values stay at B's
top. Finally, extract B's current maximum with the shorter rotation and push to A.

The operation bound is O(n²/w + nw). Until fewer than w values remain, at least w
remaining ranks are below p+w. A complete scan of A therefore removes at least w
values, bounding A's rotations by O(n²/w + n).

For B, number push events from zero. The rank x pushed at event t satisfies x < t+w.
The push permutation's total absolute displacement from sorted order is O(nw), so
its inversion count is also O(nw). B consists of top insertions in reverse event
order followed by bottom insertions in event order. With larger ranks removed, the
distance of a rank from its group's outer end counts later smaller ranks in that
group. Summed over all ranks, these distances are bounded by the push permutation's
inversions. Moving between successive maxima costs at most the sum of their
distances to the cut between the two outer ends, plus constant work per value.
Thus B's rotations total O(nw). With w proportional to sqrt(n), the overall bound
is O(n sqrt(n)); pushes and B's distribution rotations add O(n). Auxiliary storage
is O(n).

## Complex: O(n log n)

Binary LSD radix sorting examines compressed ranks from the least significant bit.
For each bit, inspect exactly n elements: rotate ones in A, push zeros to B, then
push B back. This preserves the order within each bit group. After each pass, one
more low bit is sorted. There are ceil(log2(n)) passes of at most 2n operations,
giving O(n log n) operations and O(n) auxiliary storage.

Big-O describes growth, not a guarantee that Complex beats Simple for every size.
For example, radix can emit more operations than minimum extraction at n = 50.

## Adaptive

Before any move, count inversions and divide by n(n-1)/2. Inputs with fewer than
two values have disorder zero. The thresholds are prescribed by the subject:

| Disorder | Method | Operation upper bound | Auxiliary space |
| --- | --- | --- | --- |
| below 0.2 | Simple | O(n²) | O(n) |
| 0.2 to below 0.5 | Medium | O(n sqrt(n)) | O(n) |
| 0.5 or above | Complex | O(n log n) | O(n) |

Low disorder uses the straightforward minimum extraction baseline. Medium disorder
uses a window to avoid repeatedly seeking a global minimum. High disorder uses
radix's bounded number of passes, independent of initial order. These choices meet
the required upper bounds; they do not promise the smallest operation count for
each input. An explicit selector overrides the disorder-based choice.

The sorting buffers above are O(n). Separately, the parser reserves A's capacity
using argument count and text lengths, so that allocation is O(argc + L), where L
is the total number of argument characters.

# Contributions

- bshoda: implementation and testing.
- teammate_login: replace this placeholder with the second learner's contribution.

# Resources

- The supplied Push_swap subject
- C manual pages for `write`, `malloc`, and `free`
- AI was used to draft the initial file structure, parser, operations, algorithms,
  tests, and documentation. Both learners must review, understand, and validate it.
