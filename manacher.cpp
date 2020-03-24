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
string god(string &z)
{
	int n = int(z.size());
	string ans = "";
	int rans=-1;
	int rans1=-1;
	for(int i = 0;i<2;++i)
	{
		for(int j = 0;j<n;++j)
		{
			int r = !i;
		 	if(j-R[i][j]+r==0&&(R[i][j]*2-r)>ans.size())
		 		rans =max(rans,R[i][j]*2-r);
		 	if(j+R[i][j]==n&&(R[i][j]*2-r)>ans.size())
		 		rans1 =max(rans1,R[i][j]*2-r);
		}
	}
	if(rans>rans1)
		return string(z.begin(),z.begin()+rans);	
	return string(z.end()-rans1,z.end());
}
