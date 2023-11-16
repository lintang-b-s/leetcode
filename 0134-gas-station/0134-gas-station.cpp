/*
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
intuisi: jika totalGas >= totalCost bisa dipastikan ada solusi, jika totalGas<toatlCost tidak ada solusi. 
- jika dari stasiun A ke B  bisa dilewati  & totalGas >= totalCost, dan kita start dari stasiun A bisa dipastikan kita bisa kembali ke stasiun B seetelah melalui. stasiun lain.
- jiika dari stasiun A ke B tidak bisa dilewati, maka kita coba mulai dari stasiun B


totalGas=. 5+4+3+2+1 = 15
totalCost = 3+4+5+1+2 = 15
totalGas - totalCost >= 0 ()

0. 1-3 = -2 -> curFuel. =-2
1. 2-4 = -2 -> curFuel = 0-2= -2
2. 3-5 = -2 -> curFuel = 0-2= -2
3. 4-1 = 3 -> curFuel = 0 +3 = 3 -> starIndex=. 3



*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0, totalCost=0;
        for (int g: gas){
            totalGas += g;
        }
        for (int c :cost){
            totalCost += c;
        }
        if (totalGas - totalCost < 0){
            // cout << (totalGas - totalCost) << endl;
            return -1;
        }

        int curFuel=0, startIndex = 0;
        for (int i=0; i < gas.size(); i++){
            if (curFuel < 0){
                curFuel = 0;
                startIndex = i;
            }
            curFuel += (gas[i] - cost[i]);
            // cout << "endFuel: " << curFuel << endl;
        }

        return startIndex;
    }
};