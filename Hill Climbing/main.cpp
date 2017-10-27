/*********************************************************************

This file is part of Hill Climbing (GNU GPL) - https://www.youtube.com/user/Muzkaw.

Hill Climbing is free software : you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Hill Climbing is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Hill Climbing. If not, see <http://www.gnu.org/licenses/>.

Hill Climbing codded by Muzkaw : https://www.youtube.com/user/Muzkaw
You need to link SFML 2.0 or above to run the program

********************************************************************/

#include <SFML/Graphics.hpp>
#include "Picture.h"
#include "iostream"

using namespace std ;
using namespace sf ;

int main()
{
	string path ;
	//cin>>path ;
	path="test3.jpg";

	const int width = 800 ;
	const int height = 800 ;

	RenderWindow window(VideoMode(width,height,32),"Window");

	Picture pic(path,1,&window) ;
		
	while(window.isOpen())
	{
		pic.mutate() ;
	}

}