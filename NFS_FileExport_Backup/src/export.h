/* Copyright (C) 2013-14 Green Turtles Technologies <www.greenturtles.in>, Inc.  All rights reserved.

 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Authors: Sunil Kumar <skjmca51@gmail.com>
            Ganesh Kumar <ganeshkumar14@gmail.com>
 * -*- coding: utf-8 -*-
 */


#ifndef EXPORT_H
#define EXPORT_H
char* getversion();
struct nfs* get_export_list(int*);
struct nfs{
  char ***share;
  int countshare;
};

#endif /* export.h */
