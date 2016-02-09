/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 18:31:06 by wwatkins          #+#    #+#             */
/*   Updated: 2016/02/09 18:36:33 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

void	vec3_clamp(t_vec3 *vec3, double min, double max)
{
	vec3->x > max ? vec3->x = max : 0;
	vec3->y > max ? vec3->y = max : 0;
	vec3->z > max ? vec3->z = max : 0;
	vec3->x < min ? vec3->x = min : 0;
	vec3->y < min ? vec3->y = min : 0;
	vec3->z < min ? vec3->z = min : 0;
}
