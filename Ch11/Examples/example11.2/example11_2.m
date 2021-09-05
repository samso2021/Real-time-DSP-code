%
% example11_2.m - MATLAB script for Example 11.2
%   This routine compute white balance gain and perform white balance to
%   the image file
%
%
% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

RGB = imread('example11.2.jpg');
[height, width, color] = size(RGB);
figure, imshow(RGB); title('Origianl JPEG Image');
R = sum(sum(RGB(:,:,1)));         % Compute sum of R
G = sum(sum(RGB(:,:,2)));         % Compute sum of G
B = sum(sum(RGB(:,:,3)));         % Compute sum of B
gr = 1;
gg = 1;
gb = 1;
if G<R
    if G<B   
        gr = G/R;                 % Normalized gain factor for R 
        gb = G/B;                 % Normalized gain factor for B 
    end
end
if R<G
    if R<B   
        gg = R/G;                 % Normalized gain factor for G 
        gb = R/B;                 % Normalized gain factor for B 
    end
end
if B<R
    if B<G
        gr = B/R;                 % Normalized gain factor for R 
        gg = B/G;                 % Normalized gain factor for G 
    end
end
Rw=RGB(:,:,1)*double(gr);		 % Apply normalized gain factor to R
Gw=RGB(:,:,2)*double(gg);		 % Apply normalized gain factor to G 
Bw=RGB(:,:,3)*double(gb);		 % Apply normalized gain factor to B
RGBw(:,:,1) = Rw;
RGBw(:,:,2) = Gw;
RGBw(:,:,3) = Bw;
figure, imshow(RGBw), title('White Balanced RGB Image');
