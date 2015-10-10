#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace Shared
{

	class Version
	{
	public:
		int m_Major = 0;
		int m_Minor = 0;
		int m_Build = 0;
	
		Version() {}
		Version(int Major, int Minor, int Build) { m_Major = Major; m_Minor = Minor; m_Build = Build; }
		string GetString() { return to_string(m_Major) + "." + to_string(m_Minor) + "." + to_string(m_Build); }
		// If 0: Same Version, If 1: This version is older, If -1: This version is newer
		int Compare(Version V)
		{
			if (m_Major == V.m_Major && m_Minor == V.m_Minor && m_Build == V.m_Build)
				return 0;
			if (V.m_Major > m_Major)
				return 1;
			else if (V.m_Major == m_Major)
				if (V.m_Minor > m_Minor)
					return 1;
				else if (V.m_Minor == m_Minor)
					if (V.m_Build > m_Build)
						return 1;
			return -1;
		}
	};

}