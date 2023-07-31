package main

import (
	"fmt"
	"sort"
)

/*
masukan maksimal 2 orang ke boats yang bobotnya paling kecil dan paling
besar di array jika bobot kedua orang tersebut kurang dari limit setelah itu
arraynya diperkecil dengan menggeser pointer lightestP dan heaviestP

jika bobot kedua orang tersebut lebih dari limit maka masukan org dg bobot yg
terebsar ke boats, array diperbarui dengan mengeluarkan heaviestP
kita iterasi sampai dua pointer melewati satu sama lain
*/

/*
	misal

3 2 2 1  limit 3
sorting
1 2 2 3
1 2 2
2
nil
*/
func numRescueBoats(people []int, limit int) int {
	sort.Ints(people)
	lightestP := 0
	heaviestP := len(people)-1
	boats := 0
	for heaviestP >= lightestP {
		if people[lightestP]+people[heaviestP] <= limit {
			boats++
			heaviestP--
			lightestP++
		} else {

			boats++
			heaviestP--
		}
	}

	return boats
}