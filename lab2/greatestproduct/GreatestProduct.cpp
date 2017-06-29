//
// Created by ktr on 07.03.2017.
//

#include "GreatestProduct.h"

using namespace std;

int GreatestProduct(const vector<int> &numbers, int k)
{
    if(numbers.size()>0 && k>0)
    {
        vector<int> max_numbers;
        vector<int> max_positive_only;
        int j,product=1,product_positive_only=1,if_negative=0;
        for (int i=0;i<k;i++)
        {
            max_numbers.push_back(0);
        }

        for (int v : numbers)
        {

            j=0;

            for (int i : max_numbers)
            {
                if (v==numbers[numbers.size()-1] && if_negative!=0 )
                {
                    if(if_negative%2==0)
                    {
                        if (max_numbers[k-1]>0)
                        {
                            if (v>=abs(i))
                            {
                                max_numbers.insert(max_numbers.begin()+j,v);
                                max_numbers.pop_back();
                                if(v>=0)
                                {
                                    max_positive_only.insert(max_positive_only.begin(),v);
                                    if(max_positive_only.size()>k)
                                        max_positive_only.pop_back();
                                }
                                break;
                            }

                        } else
                        {
                            if(v<0 && abs(v)>=abs(i))
                            {
                                max_numbers.insert(max_numbers.begin()+j,v);
                                max_numbers.pop_back();
                                break;
                            }
                        }
                    } else
                    {
                        if (max_numbers[k-1]>0)
                        {
                            if (v<0)
                            {
                                max_numbers.insert(max_numbers.begin()+j,v);
                                max_numbers.pop_back();

                                break;
                            }
                        } else
                        {
                            if(v>=abs(i))
                            {
                                max_numbers.insert(max_numbers.begin()+j,v);
                                max_numbers.pop_back();
                                if(v>=0)
                                {
                                    max_positive_only.insert(max_positive_only.begin(),v);
                                    if(max_positive_only.size()>k)
                                        max_positive_only.pop_back();
                                }
                                break;
                            } else{
                                max_numbers.insert(max_numbers.begin()+j,v);
                                max_numbers.pop_back();
                                if(v>=0)
                                {
                                    max_positive_only.insert(max_positive_only.begin(),v);
                                    if(max_positive_only.size()>k)
                                        max_positive_only.pop_back();
                                }
                                break;
                            }
                        }
                    }
                }
                else{
                    if (abs(v)>=abs(i))
                    {
                        if(v<0)
                        {
                            if_negative++;
                        }
                        max_numbers.insert(max_numbers.begin()+j,v);
                        max_numbers.pop_back();
                        if(v>=0)
                        {
                            max_positive_only.insert(max_positive_only.begin(),v);
                            if(max_positive_only.size()>k)
                                max_positive_only.pop_back();
                        }
                        break;
                    }
                }

                j++;

            }
        }
        cout<<endl;
        for(int i : max_numbers)
        {
            product*=i;
        }
        if(max_positive_only.size()>0)
        {
            for(int l : max_positive_only)
            {
                product_positive_only*=l;
            }
            return max(product,product_positive_only);
        }
        return product;
    }
    return 0;

}