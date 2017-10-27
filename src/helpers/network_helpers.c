/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <etregoni@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 18:22:16 by etregoni          #+#    #+#             */
/*   Updated: 2017/10/13 18:22:21 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

char *get_ip_str(void)
{
	int fd;
	struct ifreq ifr;
	char *iface;

	iface  = "en0";
	fd = socket(AF_INET, SOCK_DGRAM, 0);
	ifr.ifr_addr.sa_family = AF_INET;
	strncpy(ifr.ifr_name , iface , IFNAMSIZ - 1);
	ioctl(fd, SIOCGIFADDR, &ifr);
	close(fd);
	return (inet_ntoa(( (struct sockaddr_in *)&ifr.ifr_addr )->sin_addr));
}

// void		*get_in_addr(struct sockaddr *sa)
// {
// 	if (sa->sa_family == AF_INET)
// 		return &(((struct sockaddr_in*)sa)->sin_addr);
// 	return &(((struct sockaddr_in6*)sa)->sin6_addr);
// }
