/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:51:18 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/20 08:41:08 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &copy)
{
	(void) copy;
}

Serializer &Serializer::operator=(const Serializer &copy)
{
	(void) copy;
	return (*this);
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data *data)
{
	return (reinterpret_cast<uintptr_t>(data));
}

Data *Serializer::deserialize(uintptr_t ptr)
{
	return (reinterpret_cast<Data *>(ptr));
}