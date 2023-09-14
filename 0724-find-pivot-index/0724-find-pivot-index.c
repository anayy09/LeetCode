int pivotIndex(int *nums, int numsSize) {

  int sum = 0, var = 0;

  for (int i = 0; i < numsSize; i++) {
    sum += nums[i];
  }

  for (int i = 0; i < numsSize; i++) {

    if (var == sum - nums[i] - var) {
      return i;
    }

    var += nums[i];
  }
  
  return -1;
}