use std::cmp;

impl Solution {
    pub fn min_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let (n, m) = (grid.len(), grid[0].len());
        let mut min_sum_to = vec![vec![0; m]; n];
      
        let max_val = i32::max_value();
        for i in 0..n {
          for j in 0..m {
            let better_option = match (i, j) {
              (0, 0) => 0,
              (i, 0) => min_sum_to[i - 1][j],
              (0, j) => min_sum_to[i][j - 1],
              (i, j) => cmp::min(min_sum_to[i - 1][j], min_sum_to[i][j - 1]),
            };
            
            min_sum_to[i][j] = better_option + grid[i][j];
          }
        }

        return min_sum_to[n-1][m-1];
    }
}