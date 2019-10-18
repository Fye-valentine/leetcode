class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if(A[0].size()==1) return 0;
        int res=0;
        for(int i=0; i<A[0].size(); i++){
            for(int j=1; j<A.size(); j++){
                if((int)A[j][i]<(int)A[j-1][i]){
                    res++;
                    break; 
                }
            } 
        }      
        return res;
    }
};
