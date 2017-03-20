//
// Created by maj3 on 18.03.17.
//

#include <TinyUrl.h>

namespace tinyurl{
    std::unique_ptr<TinyUrlCodec> Init()
    {
        std::unique_ptr<TinyUrlCodec> p = std::make_unique<TinyUrlCodec>();
        //p->current_hash = {'0','0','0','0','0','0'};
        return std::make_unique<TinyUrlCodec>();
    }

    void NextHash(std::array<char, 6> *state)
    {
        int iterator[6];
        for(int i=0;i<6;i++)
        {
            iterator[i] = (*state)[i];
        }
        iterator[5]++;
        for(int i=5;i>=0;i--)
        {
            if(iterator[i]==58)
            {
                iterator[i]=65;
                break;
            }
            if(iterator[i]==91)
            {
                iterator[i]=97;
                break;
            }
            if(iterator[i]==123 && i!=0)
            {
                iterator[i]=48;
                iterator[i-1]++;
            }
        }
        for(int i=0;i<6;i++)
        {
            (*state)[i] = (char)iterator[i];
        }
    }

    std::string Encode(const std::string &url, std::unique_ptr<TinyUrlCodec> *codec)
    {
        std::string str;
        for(auto n : (*codec)->current_hash)
        {
            str.push_back(n);
        }
        (*codec)->url_map.emplace(str,url);
        NextHash(&(*codec)->current_hash);
        return "http://tinyurl.com/"+str;
    }
    std::string Decode(const std::unique_ptr<TinyUrlCodec> &codec, const std::string &hash)
    {
        std::string str;
        for(int i=6;i>=1;i--)
        {
            str.push_back(hash[hash.size()-i]);
        }
        return codec->url_map[str];
    }
}