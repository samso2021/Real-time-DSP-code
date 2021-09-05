% 
%  Project:	Chapter 10 example 10.7
%  File name:   cascad4x2.m 
%
%  Description: Bass, Treble, Boost processing
%				 
%
%  For the book "Real Time Digital Signal Processing: 
%                Fundamentals, Implementation and Application, 3rd Ed"
%                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%                Publisher: John Wiley and Sons, Ltd
%
function [d] = cascad4x2(b,c)
a = b'*c;
Coef0 = a(1,1);
Coef1 = a(2,1) + a(1,2);
Coef2 = a(3,1) + a(2,2) + a(1,3);
Coef3 = a(4,1) + a(3,2) + a(2,3);
Coef4 = a(5,1) + a(4,2) + a(3,3);
Coef5 = a(5,2) + a(4,3);
Coef6 = a(5,3);


d = [Coef0 Coef1 Coef2 Coef3 Coef4 Coef5 Coef6];