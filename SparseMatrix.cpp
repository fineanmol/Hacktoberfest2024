#include <iostream>
using namespace std;
struct element
{
    int i;
    int j;
    int x;
};
struct sparse
{
    int m;
    int n;
    int num;
    struct element *e;
};

void create(struct sparse *s)
{
    cout << "Enter the dimensions: " << endl;
    cin >> s->m >> s->n;
    cout << "Enter the number of non zero elements: ";
    cin >> s->num;
    cout << "Enter all the elememts: " << endl;
    s->e = new element[s->num];
    for (int k = 0; k < s->num; k++)
    {
        cin >> s->e[k].i >> s->e[k].j >> s->e[k].x;
    }
}
void display(struct sparse *s)
{
    int k = 0;
    cout << "Sparse Matrix is:" << endl;
    for (int i = 0; i < s->m; i++)
    {
        for (int j = 0; j < s->n; j++)
        {
            if (i == s->e[k].i && j == s->e[k].j)
                cout << s->e[k++].x << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
struct sparse *add(struct sparse s, struct sparse s1)
{
    if (s.m != s1.m && s.n != s1.n)
        return 0;
    else
    {
        int l = 0, m = 0;
        struct sparse *res;
        res=new sparse;
        res->m = s.m;
        res->n = s1.n;
        res->e = new element[s.num + s1.num];
        int count = 0;
        
        for (int k = 0; k < s.num + s1.num; k++)
        {
            if (s.e[l].i < s1.e[m].i)
            {
                res->e[k]=s.e[l++];
                count++;
            }
            else if (s.e[l].i > s1.e[m].i)
            {
                res->e[k]=s1.e[m++];
                count++;
            }
            else
            {
                if(s.e[l].j<s1.e[m].j)
                {
                    res->e[k]=s.e[l++];
                    count++;
                }
                else if(s.e[l].j>s1.e[m].j)
                {
                    res->e[k]=s1.e[m++];
                    count++;
                }
                else
                {
                    res->e[k].i=s.e[l].i;
                    res->e[k].j=s.e[l].j;
                    res->e[k].x=s.e[l++].x+s1.e[m++].x;
                    count++;
                }
            }
        }
        res->num=count;
        return res;
    }
}
int main()
{
    struct sparse s;
    cout << "Sparse Matrix 1:" << endl;
    create(&s);
    struct sparse s1;
    cout<<endl<<"Sparse Matrix 2:"<<endl;
    create(&s1);
    display(&s);
    display(&s1);

    struct sparse *res;
    res=add(s,s1);
    display(res);
    return 0;
}
