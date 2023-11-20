/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:39:58 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/20 08:43:23 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data	*data;

	data = new Data;
	data->name = "New item";
	data->value = 100;

	std::cout
		<< "The item alocated in "
		<< Serializer::serialize(data)
		<< " is a "
		<< Serializer::deserialize(Serializer::serialize(data))->name
		<< " that costs "
		<< Serializer::deserialize(Serializer::serialize(data))->value
		<< "€."
		<< std::endl;

	return (0);
}