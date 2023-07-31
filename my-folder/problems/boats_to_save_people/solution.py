class Solution:

    """
    masukan maksimal 2 orang ke boats yang bobotnya paling kecil dan paling     
    besar di array jika bobot kedua orang tersebut kurang dari limit setelah itu 
    arraynya diperkecil dengan menggeser pointer lightestP dan heaviestP
 
    jika bobot kedua orang tersebut lebih dari limit maka masukan org dg bobot yg 
    terebsar ke boats, array diperbarui dengan mengeluarkan heaviestP
   

    """
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()

        n = len(people)
        heaviestP = n - 1

        lightestP = 0

        boats=0
        while (heaviestP >= lightestP):
            if (people[lightestP] + people[heaviestP] <= limit):
                boats +=1
                heaviestP -=1
                lightestP += 1
            else:
                boats += 1
                heaviestP -=1
        
        return boats