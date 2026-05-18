int* nextGreaterElements( int* nums, int numsSize, int* returnSize ) {
	if ( nums == NULL || numsSize == 0 ) {
		*returnSize = 0;
		return NULL;
	}

	int* out = malloc( sizeof(int) * numsSize );
	int *si  = malloc( sizeof(int) * numsSize );
	int sLen = 0;

	assert(out != NULL);
	*returnSize = numsSize;

	for ( int i = numsSize * 2 - 1; i >= 0; i-- ) {
		while ( sLen != 0 && nums[si[sLen - 1]] <= nums[i % numsSize] ) {
            sLen -= 1;
        }
        out[i % numsSize] = sLen == 0 ? -1 : nums[si[sLen - 1]];
        si[sLen++] = i % numsSize;
	}

	free(si);

	return out;
}
