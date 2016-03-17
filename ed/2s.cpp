#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define MYTRACE(t) cout << #t": " << t << endl;

typedef vector<double> TypeV;
typedef vector<vector<double> > TypeVV;
typedef vector<vector<vector<double> > > TypeVVV;

struct Pattern
{
    long id;
    long type;
    long new_type;
    vector<double> data;
    bool operator<(const Pattern& p)
    {
        return type < p.type;
    }
};

bool readData(vector<Pattern>& train_data, const string& file, long f);
void prlongData(const vector<Pattern>& train_data, long f);
void prlongVVV(const TypeVVV& vvv);
void computerVVV(TypeVVV& vvv, const vector<Pattern>& train_data);
void testTestData(vector<Pattern>& test_data, const TypeVVV& vvv);
void estimateResult(const vector<Pattern>& test_data);

int main(int argc, char* argv[])
{
    vector<Pattern> train_data;
    if (!readData(train_data, "train.txt", 1))
    {
        cerr << "Read train.txt error!" << endl;
        return -1;
    }
    // prlongData(train_data, 1);
    const long D_1st = 2;
    const long D_2nd = train_data.size();
    const long D_3rd = 2;
    TypeV v(D_3rd, 0.0);
    TypeVV vv(D_2nd, v);
    TypeVVV vvv(D_1st, vv);
    computerVVV(vvv, train_data);
    // prlongVVV(vvv);

    vector<Pattern> test_data;
    if (!readData(test_data, "test.txt", 1))
    {
        cerr << "Read test.txt error!" << endl;
        return -2;
    }
    testTestData(test_data, vvv);
    prlongData(test_data, 1);
    prlongData(test_data, 2);
    estimateResult(test_data);
    return 0;
}

bool readData(vector<Pattern>& train_data, const string& file, long f)
{
    ifstream fin(file.c_str());
    if (fin.fail())
    {
        return false;
    }
    string s;
    while (getline(fin, s))
    {
        istringstream sin(s);
        double d;
        Pattern pattern;
        sin >> pattern.id;
        if (f == 1)
        {
            sin >> pattern.type;
        }
        while (sin >> d)
        {
            pattern.data.push_back(d);
        }
        train_data.push_back(pattern);
    }
    fin.close();
    return true;
}

void prlongData(const vector<Pattern>& train_data, long f)
{
    for (size_t i = 0; i < train_data.size(); ++i)
    {
        cout << train_data[i].id << '\t';
        if (f == 1)
        {
            cout << train_data[i].type << '\t';
        }
        else if (f == 2)
        {
            cout << train_data[i].new_type << '\t';
        }
        for (size_t j = 0; j < train_data[i].data.size(); ++j)
        {
            cout << train_data[i].data[j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void prlongVVV(const TypeVVV& vvv)
{
    size_t i, j, k;
    for (i = 0; i < vvv.size(); ++i)
    {
        for (j = 0; j < vvv[i].size(); ++j)
        {
            for (k = 0; k < vvv[i][j].size(); ++k)
            {
                cout << vvv[i][j][k] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
    // cout << i << endl << j << endl << k << endl;
}

long computerTypeAmount(const vector<Pattern>& train_data, long type)
{
    long ret = 0;
    for (size_t i = 0; i < train_data.size(); ++i)
    {
        if (train_data[i].type == type)
        {
            ++ret;
        }
    }
    return ret;
}

long computerAmountByValueAttributeType(const vector<Pattern>& train_data, long value, long attribute, long type)
{
    long ret = 0;
    for (size_t i = 0; i < train_data.size(); ++i)
    {
        if (train_data[i].type == type)
        {
            if (train_data[i].data[attribute] == value)
            {
                ++ret;
            }
        }
    }
    return ret;
}

void computerVVV(TypeVVV& vvv, const vector<Pattern>& train_data)
{
    size_t i, j, k;
    for (i = 0; i < vvv.size(); ++i)
    {
        long type_amount = computerTypeAmount(train_data, i);
        for (j = 0; j < vvv[i].size(); ++j)
        {
            for (k = 0; k < vvv[i][j].size(); ++k)
            {
                vvv[i][j][k] = 1.0 * computerAmountByValueAttributeType(train_data, k, j, i) / type_amount;
            }
        }
    }
}

double log2(double n)
{
    return log(n) / log(2.0);
}

void testTestData(vector<Pattern>& test_data, const TypeVVV& vvv)
{
    for (size_t t = 0; t < test_data.size(); ++t)
    {
        double p = 0.0;
        long typ = 0;
        for (size_t i = 0; i < vvv.size(); ++i)
        {
            double q = 0.0;
            for (size_t j = 0; j < vvv[i].size(); ++j)
            {
                q = q + (-log2(vvv[i][j][static_cast<unsigned long>(test_data[t].data[j])] + 0.0001));
            }
            // cout << q << '\t';
            if (q > p)
            {
                p = q;
                typ = i;
                // cout << "test" << endl;
            }
        }
        // cout << endl;
        // cout << typ << endl;
        test_data[t].new_type = typ;
    }
}

void estimateResult(const vector<Pattern>& test_data)
{
    const long D_1st = 2;
    vector<double> v(5, 0.0);
    vector<vector<double> > vv(D_1st, v);

    for (long i = 0; i < D_1st; ++i)
    {
        for (size_t j = 0; j < test_data.size(); ++j)
        {
            if (test_data[j].type == i)
            {
                ++vv[i][0];
            }
            if (test_data[j].new_type == i)
            {
                ++vv[i][1];
            }
            if (test_data[j].type == test_data[j].new_type && test_data[j].type == i)
            {
                ++vv[i][2];
            }
        }
    }
    double total_right = 0.0;
    double weighting_recall = 0.0;
    double weighting_precision = 0.0;
    for (long i = 0; i < D_1st; ++i)
    {
        cout << i << ": " << endl;
        // MYTRACE(vv[i][0]);
        // MYTRACE(vv[i][1]);
        // MYTRACE(vv[i][2]);
        cout << "Recall: " << (vv[i][3] = vv[i][2] / vv[i][0]) << endl;
        cout << "Precison: " << (vv[i][4] = vv[i][2] / vv[i][1]) << endl;
        cout << endl;
        weighting_recall += vv[i][3] * vv[i][0] / test_data.size();
        weighting_precision += vv[i][4] * vv[i][0] / test_data.size();
        total_right += vv[i][3];
    }
    cout << "right: " << total_right / test_data.size() << endl << endl;
    cout << "Weight Recall: " << weighting_recall << endl;
    cout << "Weight Precision: " << weighting_precision << endl;
    cout << endl;
}
