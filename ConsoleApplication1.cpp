#include <iostream>

using namespace std;


int main()
{
    //0925 백준 색종이 문제 (미완성.. 완전 줄여야 됨 너무 길게 작성)
    int n;
    cin >> n;

    //x, y 입력받을 배열
    int* arrX = new int[n];
    int* arrY = new int[n];

    //범위(+10씩)
    int* rX = new int[n];
    int* rY = new int[n];

    int* a = new int[n];
    a = { 0, };
 //겹치는 넓이 입력받을 배열

    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> arrX[i];
        rX[i] = arrX[i] + 10;
        cin >> arrY[i];
        rY[i] = arrY[i] + 10;
    }

    //겹치는 색종이 찾아내기
    //x, y가 둘 다 겹쳐야 함. 따라서 x나 y중 하나라도 안 겹치면 끝
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            //시작지점 검사 1. (안 겹침 && 왼쪽 - 기준 박스의 첫 부분보다 비교 박스의 끝 부분이 왼쪽 이하)
            if (rX[j] < arrX[i])
                break;
            else if (arrX[j] > rX[i])
                break;//2. 오른쪽 안 겹침 - 기준박스의 끝 부분보다 비교 박스의 시작 분이 오른쪽 이하
            else if (arrY[j] > rY[i]) //어 x는 겹치네. y 겹치나 검사!
                break;
            else if (rY[j] < arrY[i])
                break;
            //여기까지 통과한 거면 x,y둘 다 겹치는 거임. 

            //왼쪽, 위 겹치는 경우?
            if (rX[j] >= arrX[i] && arrY[j] >= arrY[i]) {
                a[i] += (rX[j] - arrX[i]) * (rY[i] - arrY[j]);
                continue;
            }
            else if (arrX[j] <= rX[i] && arrY[j] >= arrY[i]) { //오른쪽 위 겹침
                a[i] += (rX[i] - arrX[j]) * (rY[i] - arrY[j]);
                continue;
            }
            else if (rX[j] >= arrX[i] && rY[j] >= arrY[i]) { //왼쪽 아래 겹침
                a[i] += (rX[j] - arrX[i]) * (rY[j] - arrY[i]);
                continue;
            }
            else if (arrX[j] >= arrX[i] && rY[j] >= arrY[i]) { //오른쪽 아래 겹침
                a[i] += (arrX[j] - arrX[i]) * (rY[j] - arrY[i]);
                continue;
            }
        }
        sum += 10 * 10 - a[i];
    }
    printf("%d\n", sum);

    free(arrX);
    free(arrY);
    free(rX);
    free(rY);
    free(a);


}


