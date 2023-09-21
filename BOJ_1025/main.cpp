#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

bool isSqr(ll x) {
	const auto q = static_cast<ll>(sqrt(x));
	return q * q == x;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	auto nums = vector<string>(n);
	for (auto&& s : nums) {
		cin >> s;
	}

	auto ans = ll{ -1 };
	for (auto r = 0; r < n; ++r) {
		for (auto c = 0; c < m; ++c) {
			for (auto dr = -n; dr <= n; ++dr) {
				for (auto dc = -m; dc <= m; ++dc) {
					if (0 == dr && 0 == dc) {
						continue;
					}

					auto val = ll{ 0 };
					auto nr = r;
					auto nc = c;
					while (0 <= nr && nr < n &&
						0 <= nc && nc < m) {
						val *= 10;
						val += (nums[nr][nc] - '0');

						if (isSqr(val) && ans < val) {
							ans = val;
						}

						nr += dr;
						nc += dc;
					}
				}
			}
		}
	}

	cout << ans;

	return 0;
}