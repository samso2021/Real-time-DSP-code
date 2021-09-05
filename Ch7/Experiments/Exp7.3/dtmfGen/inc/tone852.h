/*
 * tone852.h
 *
 *  Created on: Jul 14, 2012
 *      Author: BLEE
 *
*  Description: This is the data file for 852 Hz tone generation
*
*  For the book "Real Time Digital Signal Processing:
*                Fundamentals, Implementation and Application, 3rd Ed"
*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
*                Publisher: John Wiley and Sons, Ltd
*
*/

const Int16 tone852[DTMF_TABLE_SIZE]={
8191, 6424, 1887, -3464, -7321, -8020, -5260, -231, 
4897, 7914, 7517, 3878, -1433, -6127, -8177, -6701, 
-2334, 3039, 7102, 8101, 5607, 693, -4518, -7782, 
-7689, -4279, 975, 5810, 8138, 6956, 2774, -2604, 
-6860, -8157, -5935, -1154, 4125, 7625, 7836, 4667, 
-514, -5474, -8073, -7190, -3205, 2161, 6596, 8186, 
6245, 1610, -3718, -7443, -7958, -5040, 51, 5121, 
7982, 7400, 3626, -1711, -6311, -8189, -6534, -2061, 
3300, 7238, 8055, 5397, 411, -4751, -7865, -7587, 
-4035, 1255, 6006, 8165, 6803, 2506, -2871, -7010, 
-8126, -5737, -873, 4367, 7724, 7749, 4432, -796, 
-5681, -8116, -7050, -2943, 2433, 6760, 8171, 6058, 
1332, -3968, -7557, -7886, -4814, 334, 5339, 8041, 
7274, 3370, -1987, -6487, -8190, -6360, -1786, 3557, 
7367, 7999, 5181, 128, -4979, -7940, -7475, -3787, 
1534, 6194, 8183, 6641, 2235, -3134, -7152, -8086, 
-5531, -591, 4604, 7813, 7653, 4191, -1077, -5882, 
-8149, -6902, -2677, 2701, 6915, 8147, 5864, 1052, 
-4213, -7662, -7805, -4582, 616, 5550, 8090, 7140, 
3110, -2260, -6656, -8181, -6178, -1509, 3810, 7486, 
7933, 4959, -154, -5201, -8004, -7355, -3534, 1811, 
6376, 8190, 6472, 1962, -3394, -7286, -8036, -5319, 
-308, 4835, 7893, 7547, 3946, -1357, -6075, -8173, 
-6745, -2408, 2967, 7063, 8112, 5663, 770, -4453, 
-7757, -7715, -4345, 898, 5755, 8129, 6997, 2847, 
-2531, -6817, -8163, -5988, -1230, 4058, 7596, 7858, 
4730, -437, -5416, -8060, -7226, -3276, 2086, 6550, 
8188, 6294, 1686, -3649, -7411, -7976, -5101, -25, 
5060, 7964, 7433, 3695, -1635, -6261, -8186, -6581, 
-2136, 3229, 7202, 8069, 5455, 488, -4688, -7843, 
-7615, -4102, 1179, 5953, 8159, 6846, 2580, -2798, 
-6970, -8135, -5791, -949, 4301, 7697, 7774, 4497, 
-719, -5625, -8105, -7089, -3015, 2359, 6716, 8176, 
6110, 1408, -3900, -7527, -7907, -4876, 257, 5280, 
8025, 7309, 3440, -1912, -6440, -8190, -6408, -1862, 
3487, 7332, 8015, 5240, 205, -4918, -7920, -7507, 
-3855, 1458, 6144, 8179, 6686, 2309, -3063, -7114, 
-8098, -5588, -668, 4539, 7790, 7680, 4257, -1001, 
-5828, -8141, -6943, -2750, 2628, 6874, 8154, 5917, 
1128, -4147, -7634, -7828, -4646, 539, 5493, 8077, 
7177, 3182, -2186, -6611, -8185, -6228, -1585, 3741, 
7454, 7952, 5020, -77, -5141, -7988, -7389, -3603, 
1736, 6327, 8189, 6519, 2037, -3323, -7250, -8050, 
-5378, -385, 4772, 7872, 7577, 4013, -1281, -6023, 
-8167, -6789, -2482, 2895, 7023, 8123, 5718, 847, 
-4388, -7732, -7741, -4410, 822, 5700, 8119, 7037, 
2919, -2457, -6774, -8169, -6040, -1306, 3991, 7567, 
7879, 4793, -360, -5358, -8045, -7262, -3347, 2012, 
6503, 8189, 6343, 1761, -3580, -7378, -7993, -5161, 
-102, 4999, 7946, 7465, 3764, -1560, -6211, -8184, 
-6626, -2211, 3158, 7165, 8081, 5512, 565, -4625, 
-7821, -7643, -4169, 1103, 5900, 8152, 6888, 2653, 
-2726, -6929, -8144, -5846, -1026, 4235, 7671, 7798, 
4561, -642, -5569, -8094, -7127, -3086, 2285, 6671, 
8180, 6161, 1484, -3832, -7496, -7927, -4938, 180, 
5221, 8010, 7344, 3510, -1836, -6392, -8190, -6456, 
-1937, 3417, 7298, 8031, 5300, 283, -4856, -7900, 
-7537, -3923, 1382, 6092, 8174, 6730, 2383, -2991, 
-7076, -8109, -5644, -745, 4475, 7765, 7706, 4323, 
-924, -5773, -8132, -6983, -2823, 2555, 6831, 8161, 
5971, 1205, -4080, -7606, -7851, -4709, 462, 5436, 
8064, 7214, 3253, -2111, -6565, -8187, -6278, -1661, 
3672, 7422, 7970, 5081, 0, -5081, -7970, -7422, 
-3672, 1660, 6278, 8187, 6565, 2111, -3252, -7214, 
-8064, -5436, -462, 4709, 7851, 7606, 4080, -1205, 
-5970, -8161, -6831, -2555, 2822, 6983, 8132, 5773, 
924, -4323, -7706, -7765, -4475, 745, 5644, 8109, 
7076, 2991, -2383, -6730, -8174, -6092, -1382, 3923, 
7537, 7900, 4856, -282, -5299, -8031, -7298, -3417, 
1937, 6456, 8190, 6392, 1837, -3510, -7344, -8010, 
-5221, -180, 4938, 7927, 7496, 3832, -1484, -6161, 
-8180, -6671, -2285, 3086, 7127, 8094, 5569, 642, 
-4561, -7798, -7671, -4235, 1026, 5846, 8144, 6929, 
2726, -2653, -6888, -8152, -5900, -1103, 4169, 7643, 
7821, 4625, -565, -5512, -8081, -7165, -3158, 2210, 
6626, 8184, 6211, 1560, -3764, -7465, -7946, -5000, 
102, 5161, 7993, 7378, 3580, -1761, -6343, -8189, 
-6503, -2012, 3347, 7262, 8045, 5358, 360, -4793, 
-7879, -7567, -3991, 1306, 6040, 8169, 6774, 2457, 
-2919, -7037, -8119, -5700, -822, 4410, 7740, 7732, 
4389, -847, -5718, -8123, -7024, -2895, 2482, 6789, 
8167, 6023, 1281, -4013, -7577, -7872, -4772, 385, 
5378, 8050, 7250, 3323, -2036, -6519, -8189, -6327, 
-1736, 3603, 7389, 7988, 5141, 77, -5020, -7952, 
-7454, -3741, 1585, 6228, 8185, 6611, 2186, -3181, 
-7177, -8077, -5493, -540, 4646, 7828, 7634, 4147, 
-1128, -5917, -8154, -6874, -2628, 2750, 6943, 8141, 
5828, 1001, -4257, -7680, -7790, -4540, 668, 5588, 
8098, 7114, 3063, -2309, -6686, -8179, -6144, -1459, 
3855, 7507, 7920, 4918, -205, -5240, -8015, -7332, 
-3487, 1862, 6408, 8190, 6440, 1912, -3440, -7309, 
-8026, -5280, -257, 4876, 7907, 7527, 3900, -1408, 
-6109, -8176, -6716, -2359, 3015, 7089, 8105, 5625, 
719, -4496, -7774, -7698, -4301, 949, 5791, 8135, 
6970, 2798, -2579, -6846, -8159, -5953, -1179, 4102, 
7615, 7843, 4688, -488, -5455, -8069, -7202, -3229, 
2136, 6580, 8186, 6261, 1635, -3695, -7433, -7964, 
-5060, 25, 5101, 7976, 7411, 3649, -1686, -6294, 
-8188, -6550, -2086, 3276, 7226, 8060, 5416, 437, 
-4730, -7858, -7596, -4058, 1230, 5988, 8163, 6817
};