vector<int>R[2];
//R0 odd
//R1 even
void mnchr(string &s)
{
	int n = int(s.size());
	for(int i = 0;i<2;++i){
		for(int j = 0 ,l = 0, r = -1;j<n;++j)
		{
			int k = (j>r)? !i:min(R[i][l+r-j+i],r-j+1);
			while(0<=j-k-i && j+k<n && s[j-k-i]==s[j+k])
			{
				k++;
			}
			R[i][j]=k--;
			if(j+k>r)
			{
				l = j-k-i;
				r = j+k;
			}
		}
	}
}
