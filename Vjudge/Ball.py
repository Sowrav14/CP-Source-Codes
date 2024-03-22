def count_self_murderers_optimized(N, beauty, intellect, richness):
  # Combine attributes into a single key and sort in descending order
  combined_key = list(zip(beauty, intellect, richness))
  combined_key.sort(reverse=True)

  dominance_count = 0
  self_murderers = 0

  # Previous lady's attributes for comparison (initialized with dummy values)
  prev_beauty, prev_intellect, prev_richness = float('inf'), float('inf'), float('inf')

  for b, i, r in combined_key:
    # Update dominance for previous lady and all before her (if attributes are better)
    if b < prev_beauty or i < prev_intellect or r < prev_richness:
      dominance_count += 1

    # Current lady's dominance based on previously calculated count
    current_dominance = dominance_count

    # Count self-murderers based on current lady's dominance
    if current_dominance > 0:
      self_murderers += 1

    # Update previous lady's attributes for comparison
    prev_beauty, prev_intellect, prev_richness = b, i, r

  return self_murderers

# Read input
N = int(input())
beauty = list(map(int, input().split()))
intellect = list(map(int, input().split()))
richness = list(map(int, input().split()))

# Find number of self-murderers (optimized)
result = count_self_murderers_optimized(N, beauty, intellect, richness)

# Print output
print(result)
