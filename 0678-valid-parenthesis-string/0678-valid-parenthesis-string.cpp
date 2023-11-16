/*


*/
class Solution {
public:
    bool checkValidString(string s) {
        int lo=0, hi=0;
        for (char c :s) {
            lo += c == '(' ? 1 : -1;
            hi += c == ')' ? -1 : 1;
            if (hi < 0) {break;} // terlalu banyak ')'
            lo = max(lo, 0);
            cout << lo << endl;
        }
        cout << "end:  " << lo << endl;
        // jika lo > 0 , terlalu banyak '('
        return lo ==0;
    }
};