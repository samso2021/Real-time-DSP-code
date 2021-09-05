% 
%  Project:	Chapter 10 example 10.7
%  File name:   cascad2x2.m 
%
%  Description: Bass, Treble, Boost processing
%				 
%
%  For the book "Real Time Digital Signal Processing: 
%                Fundamentals, Implementation and Application, 3rd Ed"
%                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%                Publisher: John Wiley and Sons, Ltd
%
function [d] = cascad2x2(b,c)
a = b'*c;
Coef0 = a(1,1);
Coef1 = a(2,1) + a(1,2);
Coef2 = a(3,1) + a(2,2) + a(1,3);
Coef3 = a(3,2) + a(2,3);
Coef4 = a(3,3);
d = [Coef0 Coef1 Coef2 Coef3 Coef4];