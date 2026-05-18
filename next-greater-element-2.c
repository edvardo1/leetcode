int* nextGreaterElements( int *nums, int numsSize, int *returnSize ) {
	if ( nums == NULL || numsSize == 0 ) {
		*returnSize = 0;
		return NULL;
	}

	int *out = malloc( sizeof(int) * numsSize );
	assert(out != NULL);
	*returnSize = numsSize;

	for ( int i = 0; i < numsSize; i++ ) {
		int num = nums[i];
		int nextGreater = -1;

		for ( int j = 1; j < numsSize; j++ ) {
			int jn = nums[( i + j ) % numsSize];
			if ( jn > num ) {
				nextGreater = jn;
				break;
			}
		}
		out[i] = nextGreater;
	}

	return out;
}
