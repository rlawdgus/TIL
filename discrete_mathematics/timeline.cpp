#include <fstream>
#include <algorithm>
using namespace std;

typedef struct Date {
	int year;
	int month;
	int day;
	int sd;	//0:start, 1:dest
	int weight;
}Date;

Date date[200000];

bool compare(const Date date, const Date date2) {
	if (date.weight == date2.weight) return date.sd > date2.sd;	//가중치가 같을 경우 end를 우선
	return date.weight < date2.weight;
}

int weighting(int year, int month, int day) {
	return year * 372 + month * 31 + day;
}

int timeline(int length) {
	int max = 0, cnt = 0;

	for (int i = 0; i < length; i++) {
		if (date[i].sd == 0) {
			cnt++;
			if(max < cnt) max = cnt; 
		}
		else cnt--;
	}

	return max;
}

int main() {
	ifstream inp("timeline.inp");
	ofstream out("timeline.out");

	int T, N;
	char dot;

	inp >> T;
	while (T--) {
		inp >> N;
		N *= 2;
		for (int i = 0; i < N; i += 2) {
			inp >> date[i].year >> dot >> date[i].month >> dot >> date[i].day;
			date[i].weight = weighting(date[i].year, date[i].month, date[i].day);//날짜 가중치 저장
			date[i].sd = 0;	//왼쪽 입력(start)

			inp >> date[i + 1].year >> dot >> date[i + 1].month >> dot >> date[i + 1].day;
			date[i + 1].weight = weighting(date[i + 1].year, date[i + 1].month, date[i + 1].day);//날짜 가중치 저장
			date[i + 1].sd = 1;	//오른쪽 입력(dest)
		}
		sort(date, date + N, compare);//가중치 기준으로 정렬

		out << timeline(N) << '\n';
	}

	inp.close();
	out.close();
	return 0;
}