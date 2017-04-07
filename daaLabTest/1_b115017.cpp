#include <iostream>
#include <vector>
struct student{
	int ht;
	int wt;
	bool sold;
};

bool allSold(student s[], int m)
{
	for(int i = 0;i <  m; i++)
		if(s[i].sold == false)
			return false;
	return true;
}

int main()
{
	int t;
	std::cin>>t;
	while(t--)
	{
		int m;
		std::cin>>m;
		student s[m];
		for(int i = 0;i < m; i++)
		{
			std::cin>>s[i].ht>>s[i].wt;
			s[i].sold = false;
		}

		int team_size[100];
		for(int i = 0;i < 100; i++)
			team_size[i] = 0;
		int totalTeams = 0;


		while(!allSold(s, m))			//	 untill all players are sold
		{
//			std::cout<<"inside while"<<std::endl;
			bool afraid[m];
			for(int i = 0;i < m; i++)
				afraid[i] =  false;
			for(int i = 0;i < m; i++)		//	selects an unsold player
			{
				if(s[i].sold)
					continue;
				int curr = i;
			//	std::cout<<"curr = "<<curr<<std::endl;
				for(int j = 0;j < m; j++)
				{
					if(j == curr || s[j].sold)
						continue;
			//		std::cout<<"s[curr].wt = "<<s[curr].wt<<" s[j].wt = "<<s[j].wt<<" s[curr].ht = "<<s[curr].ht<<" s[j].ht = "<<s[j].ht<<std::endl;
					if(s[curr].wt <= s[j].wt && s[curr].ht <= s[j].ht)
					{
						afraid[curr] = true;
						break;
					}
				}
			}
		//	std::cout<<"processing done"<<std::endl;
			for(int i = 0; i < m; i++)
			{
				if(s[i].sold || afraid[i] == true)
					continue;
		//		std::cout<<i<<std::endl;
				team_size[totalTeams]++;
				s[i].sold = true;
			}
			totalTeams++;
		}
		std::cout<<totalTeams<<std::endl;
		for(int i = 0;i < totalTeams; i++)
		{
			std::cout<<team_size[i]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}