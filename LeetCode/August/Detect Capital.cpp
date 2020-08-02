class Solution 
{
    public:
            bool detectCapitalUse(string word) 
            {
                int flag = 0;
                
                for(int i = 0 ; i < word.size() ; i++)
                {
                    if(word[i] >= 'a' && word[i] <= 'z' && flag == 1)
                        return false;
                    
                    if(word[i] >= 'A' && word[i] <= 'Z' && flag == 0)
                    {
                        if(i==1)
                        {
                            if(word[0] >= 'A' && word[0] <= 'Z')
                                flag = 1;
                            else
                                return false;
                        }
                        else if(i > 1)
                            if(flag != 1)
                                return false;
                    }

                }
                return true;
            }
};