/*
 * tone1336.h
 *
 *  Created on: Jul 14, 2012
 *      Author: BLEE
 *
*  Description: This is the data file for 1336 Hz tone generation
*
*  For the book "Real Time Digital Signal Processing:
*                Fundamentals, Implementation and Application, 3rd Ed"
*                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
*                Publisher: John Wiley and Sons, Ltd
*
*/

const Int16 tone1336[DTMF_TABLE_SIZE]={
8191, 4080, -4125, -8190, -4035, 4169, 8190, 3991, 
-4213, -8189, -3946, 4257, 8188, 3900, -4301, -8186, 
-3855, 4345, 8185, 3810, -4388, -8183, -3764, 4432, 
8180, 3718, -4475, -8177, -3672, 4518, 8174, 3626, 
-4561, -8171, -3580, 4604, 8167, 3534, -4646, -8163, 
-3487, 4688, 8159, 3440, -4730, -8154, -3394, 4772, 
8149, 3347, -4814, -8144, -3300, 4856, 8138, 3253, 
-4897, -8132, -3205, 4938, 8126, 3158, -4979, -8119, 
-3110, 5020, 8112, 3063, -5060, -8105, -3015, 5101, 
8098, 2967, -5141, -8090, -2919, 5181, 8081, 2871, 
-5221, -8073, -2822, 5260, 8064, 2774, -5300, -8055, 
-2726, 5339, 8045, 2677, -5378, -8036, -2628, 5416, 
8025, 2580, -5455, -8015, -2531, 5493, 8004, 2482, 
-5531, -7993, -2433, 5569, 7982, 2383, -5607, -7970, 
-2334, 5644, 7958, 2285, -5681, -7946, -2235, 5718, 
7933, 2186, -5755, -7920, -2136, 5791, 7907, 2086, 
-5828, -7893, -2037, 5864, 7879, 1987, -5900, -7865, 
-1937, 5935, 7851, 1887, -5970, -7836, -1837, 6006, 
7821, 1786, -6040, -7805, -1736, 6075, 7790, 1686, 
-6109, -7774, -1635, 6144, 7757, 1585, -6178, -7741, 
-1534, 6211, 7724, 1484, -6245, -7706, -1433, 6278, 
7689, 1382, -6311, -7671, -1332, 6343, 7653, 1281, 
-6376, -7634, -1230, 6408, 7615, 1179, -6440, -7596, 
-1128, 6472, 7577, 1077, -6503, -7557, -1026, 6534, 
7537, 975, -6565, -7517, -924, 6596, 7496, 873, 
-6626, -7475, -822, 6656, 7454, 770, -6686, -7433, 
-719, 6716, 7411, 668, -6745, -7389, -617, 6774, 
7367, 565, -6803, -7344, -514, 6831, 7321, 462, 
-6860, -7298, -411, 6888, 7274, 360, -6915, -7250, 
-308, 6943, 7226, 257, -6970, -7202, -205, 6997, 
7177, 154, -7023, -7152, -102, 7050, 7127, 51, 
-7076, -7102, 0, 7102, 7076, -51, -7127, -7050, 
102, 7152, 7024, -154, -7177, -6997, 205, 7202, 
6970, -257, -7226, -6943, 308, 7250, 6915, -360, 
-7274, -6888, 411, 7298, 6860, -462, -7321, -6831, 
514, 7344, 6803, -565, -7367, -6774, 616, 7389, 
6745, -668, -7411, -6716, 719, 7433, 6686, -770, 
-7454, -6656, 822, 7475, 6626, -873, -7496, -6596, 
924, 7517, 6565, -975, -7537, -6534, 1026, 7557, 
6503, -1077, -7577, -6472, 1128, 7596, 6440, -1179, 
-7615, -6408, 1230, 7634, 6376, -1281, -7653, -6343, 
1332, 7671, 6311, -1382, -7689, -6278, 1433, 7706, 
6245, -1484, -7724, -6211, 1534, 7740, 6178, -1585, 
-7757, -6144, 1635, 7774, 6110, -1686, -7790, -6075, 
1736, 7805, 6041, -1786, -7821, -6006, 1836, 7836, 
5971, -1887, -7851, -5935, 1937, 7865, 5900, -1987, 
-7879, -5864, 2036, 7893, 5828, -2086, -7907, -5791, 
2136, 7920, 5755, -2186, -7933, -5718, 2235, 7946, 
5681, -2285, -7958, -5644, 2334, 7970, 5607, -2383, 
-7982, -5569, 2433, 7993, 5531, -2482, -8004, -5493, 
2531, 8015, 5455, -2579, -8025, -5416, 2628, 8036, 
5378, -2677, -8045, -5339, 2726, 8055, 5300, -2774, 
-8064, -5260, 2822, 8073, 5221, -2871, -8081, -5181, 
2919, 8090, 5141, -2967, -8098, -5101, 3015, 8105, 
5060, -3063, -8112, -5020, 3110, 8119, 4979, -3158, 
-8126, -4938, 3205, 8132, 4897, -3252, -8138, -4856, 
3300, 8144, 4814, -3347, -8149, -4772, 3394, 8154, 
4730, -3440, -8159, -4688, 3487, 8163, 4646, -3533, 
-8167, -4604, 3580, 8171, 4561, -3626, -8174, -4518, 
3672, 8177, 4475, -3718, -8180, -4432, 3764, 8183, 
4389, -3809, -8185, -4345, 3855, 8186, 4301, -3900, 
-8188, -4257, 3945, 8189, 4213, -3991, -8190, -4169, 
4035, 8190, 4125, -4080, -8190, -4080, 4125, 8190, 
4035, -4169, -8190, -3991, 4213, 8189, 3946, -4257, 
-8188, -3900, 4301, 8186, 3855, -4345, -8185, -3810, 
4388, 8183, 3764, -4432, -8180, -3718, 4475, 8177, 
3672, -4518, -8174, -3626, 4561, 8171, 3580, -4603, 
-8167, -3534, 4646, 8163, 3487, -4688, -8159, -3440, 
4730, 8154, 3394, -4772, -8149, -3347, 4814, 8144, 
3300, -4856, -8138, -3253, 4897, 8132, 3205, -4938, 
-8126, -3158, 4979, 8119, 3110, -5020, -8112, -3063, 
5060, 8105, 3015, -5101, -8098, -2967, 5141, 8090, 
2919, -5181, -8081, -2871, 5221, 8073, 2823, -5260, 
-8064, -2774, 5299, 8055, 2726, -5339, -8045, -2677, 
5378, 8036, 2628, -5416, -8026, -2580, 5455, 8015, 
2531, -5493, -8004, -2482, 5531, 7993, 2433, -5569, 
-7982, -2383, 5607, 7970, 2334, -5644, -7958, -2285, 
5681, 7946, 2235, -5718, -7933, -2186, 5755, 7920, 
2136, -5791, -7907, -2086, 5828, 7893, 2037, -5864, 
-7879, -1987, 5899, 7865, 1937, -5935, -7851, -1887, 
5970, 7836, 1837, -6006, -7821, -1786, 6040, 7805, 
1736, -6075, -7790, -1686, 6109, 7774, 1635, -6144, 
-7757, -1585, 6178, 7741, 1534, -6211, -7724, -1484, 
6245, 7706, 1433, -6278, -7689, -1383, 6311, 7671, 
1332, -6343, -7653, -1281, 6376, 7634, 1230, -6408, 
-7615, -1179, 6440, 7596, 1128, -6472, -7577, -1077, 
6503, 7557, 1026, -6534, -7537, -975, 6565, 7517, 
924, -6596, -7496, -873, 6626, 7475, 822, -6656, 
-7454, -770, 6686, 7433, 719, -6716, -7411, -668, 
6745, 7389, 617, -6774, -7367, -565, 6803, 7344, 
514, -6831, -7321, -463, 6860, 7298, 411, -6888, 
-7274, -360, 6915, 7250, 308, -6943, -7226, -257, 
6970, 7202, 205, -6997, -7177, -154, 7023, 7152, 
103, -7050, -7127, -51, 7076, 7102, 0, -7102, 
-7076, 51, 7127, 7050, -102, -7152, -7024, 154, 
7177, 6997, -205, -7202, -6970, 257, 7226, 6943, 
-308, -7250, -6915, 360, 7274, 6888, -411, -7298, 
-6860, 462, 7321, 6831, -514, -7344, -6803, 565, 
7366, 6774, -616, -7389, -6745, 668, 7411, 6716, 
-719, -7433, -6686, 770, 7454, 6656, -821, -7475
};