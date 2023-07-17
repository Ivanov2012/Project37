#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
	int x;
};


void sorok() {
    setlocale(LC_ALL, "Rus");
    int N;
    cout << "������� ���������� �����: ";
    cin >> N;

    vector<Point> points(N);
    cout << "������� ���������� �����: ";
    for (int i = 0; i < N; ++i) {
        cin >> points[i].x;
    }

    double epsilon;
    cout << "������� �������� epsilon: ";
    cin >> epsilon;

   
    vector<int> labels(N, -1);
    int cluster_label = 0;

    for (int i = 0; i < N; ++i) {
        if (labels[i] != -1) {
            continue;
        }

        labels[i] = cluster_label;

        for (int j = i + 1; j < N; ++j) {
            if (abs(points[i].x - points[j].x) <= epsilon) {
                labels[j] = cluster_label;
            }
        }

        for (int j = i - 1; j >= 0; --j) {
            if (abs(points[i].x - points[j].x) <= epsilon) {
                labels[j] = cluster_label;
            }
        }

        cluster_label++;
    }

   
     

    vector<double> distances(cluster_label, 0.0);

    for (int i = 0; i < N; ++i) {
        double min_point = points[i].x;
        double max_point = points[i].x;

        for (int j = 0; j < N; ++j) {
            if (labels[j] == labels[i]) {
                min_point = min(min_point, static_cast<double>(points[j].x));
                max_point = max(max_point, static_cast<double>(points[j].x));
            }
        }

        distances[labels[i]] = max_point - min_point;
    }

    // ����� �����������
    cout << "���������� ��������� ��������: " << cluster_label << endl;
    cout << "���������� ����� �������� ������� ������ �������: ";
    for (double distance : distances) {
        cout << distance << " ";
    }
    cout << endl;
    

}

double f(double x) {
    return x * x - 5;
}

void trith(double a, double b, int max_iterations) {
    double c;
    int i = 1;
    while (i <= max_iterations) {
        c = (a + b) / 2;
        cout << "Iteration " << i << ": x = " << c << ", f(x) = " << f(c) << endl;
        if (f(c) == 0 || (b - a) / 2 < 0.0001) {
            break;
        }
        i++;
        if (f(c) * f(a) > 0) {
            a = c;
        }
        else {
            b = c;
        }
    }
    printf("%+06d\n", int(1000 * c));
}





int main()
{
    setlocale(LC_ALL, "Rus");
    double a = 2, b = 3, epsilon = 0.001;
    int input;
    int l = 1;
    while (l == 1)
    {

        cout << endl << "������� 1 ��� ���������� ������ 41." << endl;
        cout << "������� 2 ��� ���������� ������ 36" << endl;
        cout << "������� 0 ��� ������." << endl << endl;
        cin >> input;
        switch (input)
        {
        case 1: sorok(); break;
        case 2: trith(2,3,10);break; 
        case 0: input = 0; break;
        }
        system("pause");
    }
    return 0;

}