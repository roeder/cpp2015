for (i in paste0('5_', 1:10, '.cpp')) {
  cmd <- paste('touch', i)
  system(cmd)
}
  
# 2.4
u <- c(1, 2, 3)
v <- c(6, 5, 4)
A <- matrix(c(1, 5, 0, 7, 1, 2, 0, 0, 1), nrow = 3, byrow = T)
B <- matrix(c(-2, 0, 1, 1, 0, 0, 4, 1, 0), nrow = 3, byrow = T)
w <- u - 3 * v

x <- u - v
y <- A %*% u
z <- A %*% u -v
C <- 4 * A - 3 * B
D <- A %*% B

# 2.5
A <- matrix(c(4, 10, 1, 1), nrow = 2, byrow = T)
inv_A <- solve(A)

# 3.3 
library(ggplot2)
d <- read.table('Documents/ku_courses/cpp2015/week1_2/xy.dat', 
                col.names = c('x', 'y'), sep = ",")

ggplot(d, aes(x = x, y = y)) + geom_point() + ylim(0.2, 1)
