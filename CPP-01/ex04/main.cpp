/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:33:37 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/24 16:03:02 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string.h>
# include <fstream>
# include <sstream>

std::string	replace_occurence(std::string buf, std::string s1, std::string s2)
{
	std::string new_buf;
	size_t cur_pos = 0;
	size_t prev_pos = 0;
	
	while ((cur_pos = buf.find(s1, prev_pos)) != std::string::npos)
	{
		new_buf += buf.substr(prev_pos, cur_pos - prev_pos);
		new_buf += s2;
		prev_pos = cur_pos + s1.length();
	}
	new_buf += buf.substr(prev_pos);
	return(new_buf);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: Invalid number of args\n";
		std::cerr << "Program usage : ./sed <file> <s1> <s2>\n";
		return(1);
	}
	std::ifstream file(argv[1]);
	if (!file)
	{
		std::cerr << "Error: cannot open the file\n";
		return (1);
	}
	std::string Newfile = std::string(argv[1]) + "_REPLACE";
	std::ofstream Replaced(Newfile.c_str());
	if (!Replaced)
	{
		std::cerr << "Error: cannot create the new file\n";
		return (1);
	}
	std::ostringstream buffer;
	buffer << file.rdbuf();
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	Replaced << replace_occurence(buffer.str(), s1, s2);

	file.close();
	Replaced.close();
}
