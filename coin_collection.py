__author__ = 'cimamoglu'
# http://www.glassdoor.com/Interview/There-are-n-pots-with-different-gold-coins-in-them-Two-players-play-a-game-where-each-player-can-select-a-pot-at-either-QTN_100099.htm
class CoinCollector():
    def __init__(self, coins):
        self.coins = coins
        self.n = len(coins)
        self.arr = [[None for i in range(self.n)] for j in range(self.n)]
        for i in range(self.n):
            if self.n % 2 == 0:
                self.arr[i][i] = (0, self.coins[i])
            else:
                self.arr[i][i] = (self.coins[i], 0)
        # self.calc(0, self.n - 1)

    def calc(self, i, j):
        if self.arr[i][j] is not None:
            return self.arr[i][j]
        pos = ((j - i + 1) % 2) ^ (self.n % 2)
        res1 = self.calc(i + 1, j)
        res2 = self.calc(i, j - 1)
        # print (res1, res2, i, j)
        if res1[pos] + self.coins[i] > res2[pos] + self.coins[j]:
            if pos == 0:
                self.arr[i][j] = (res1[0] + self.coins[i], res1[1])
            else:
                self.arr[i][j] = (res1[0], res1[1] + self.coins[i])
        else:
            if pos == 0:
                self.arr[i][j] = (res2[0] + self.coins[j], res2[1])
            else:
                self.arr[i][j] = (res2[0], res2[1] + self.coins[j])
        return self.arr[i][j]
