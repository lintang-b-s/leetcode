class Solution {
    public List<List<Integer>> generate(int numRows) {

        List<List<Integer>> list = new ArrayList<>();

        if (numRows <= 0) {
            return list;
        }

        List<Integer> prev = new ArrayList<>();
        prev.add(1);
        list.add(prev);
        if (numRows == 1) {
            return list;
        }

        for (int i = 2; i <= numRows; i++) {
            List<Integer> current = new ArrayList<>(prev);

            for (int j = 1; j < i; j++) {

                if (j < prev.size()) {
                    int add = prev.get(j) + prev.get(j - 1);
                    current.set(j, add);
                } else {

                    current.add(1);
                }
            }

            list.add(current);
            prev = current;
        }

        return list;
    }
}