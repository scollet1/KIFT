/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kift.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 17:30:50 by scollet           #+#    #+#             */
/*   Updated: 2017/10/04 17:30:51 by scollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KIFT_H
#define KIFT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <netdb.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <assert.h>
#include <pocketsphinx.h>
#include <sphinxbase/ad.h>
#include <sphinxbase/err.h>
//#include "portaudio.h"
// Leaving portaudio out until we have a use for it, build intructions
// depend on use case.
#include "audio.h"

# define AUDIO_PATH "src/client/audio/"
# define BACKLOG 16
# define PORT "4242"
# define NAME "SELF-AWARE-BATTLE-ROBOT"
# define IP "10.112.6.9"
# define MAXDATASIZE 100
# define S_RATE (44100)
# define BUF_SIZE 512

typedef struct				s_client_connection
{
	int						sock;
	struct addrinfo		*p;
}							t_client_connection;

typedef struct	s_connection
{
	int			socket_desc;
	int			client_sock;
	char		client_message[BUF_SIZE];
	struct		sockaddr_in server;
	struct		sockaddr_in client;
} t_connection;

typedef enum
{
	UTT_STATE_WAITING = 0,
	UTT_STATE_LISTENING,
	UTT_STATE_FINISHED,
	UTT_STATE_ERROR,
	UTT_STATE_MAX,
	UTT_STATE_QUIT
} t_utt_states;

int   example(char *str);
char	*get_ip_str(void);
const char *recognize_from_microphone();

#endif
