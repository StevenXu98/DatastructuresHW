void qsort(int a[], int l, int r)
{
	if(r > l){
		int i = r, j = l;
		int x = a[l];
		while(i > j){
			while(i > j && a[j] >= x)
				j--;
			if(i > j)
				a[i++] = a[j];

			while(i > j && a[i] <= x)
				i++;
			if(i > j)
				a[j--] = a[i];
		}
		a[i] = x;
		qsort(a, l, i-1);
		qsort(a, i+1, r);		
	}
}