/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:20:14 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/02 13:27:27 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

int	main()
{
	Data data = {"Hello, World!"};

    std::cout << "Original Data pointer: " << &data << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data pointer: " << deserializedData << std::endl;
    
    if (deserializedData == &data) {
        std::cout << "Serialization and deserialization successful!" << std::endl;
        std::cout << "Data text: " << deserializedData->name << std::endl;
    } else {
        std::cout << "Error: pointers do not match!" << std::endl;
    }

    return 0;
}