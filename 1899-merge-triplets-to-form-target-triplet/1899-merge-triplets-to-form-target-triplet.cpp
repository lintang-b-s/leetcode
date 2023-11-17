/*
-  a=[1,8,4] dan b=[1,7,5] dimerge tidak bisa jadi [2,7,5], karena max(a[1], b[1]) = 8
- a=[1,8,4]  dan b=[2,5,3] dimerge tidak bisa jadi [2,7,5] dg alasan yg sama.
- remove triplet yg ada elemen yg lebih besar dari elemnen triplet target.
- dari triplet yg sudah difilter, cek apakah ada elemen di triplet yg sama dg elemen target. jika ada berarti ada beberapa triplet yg bisa di merge utk jadi target.
- 
*/


class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_map<int, bool> tripletOcc;
        set<int> good;

        for (int i =0 ; i <triplets.size(); i++){
            for (int j =0; j < triplets[0].size(); j++){
                tripletOcc[triplets[i][j]] = true;
            }
        }

        for (auto& t : target) {
            if (tripletOcc[t] == false){
                return false;
            }
        }

        for (int i =0 ; i <triplets.size(); i++){

            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]) {
                continue;
            }

            for (int j =0; j < triplets[0].size(); j++){
               
                if (triplets[i][j] == target[j]){
                    
                    good.insert(j);
                }
            }
        }
        
        return good.size() == target.size();
    }
};