%
% example8_2.m - MATLAB code for Example 8.2
%
% Find the location that makes the crosscorelation maximum

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%

clear;
% Open data files
fid1 = fopen('rtfar.pcm', 'rb');    
fid2 = fopen('rtmic.pcm', 'rb');
% Read data files
x = fread(fid1, 'int16');                   
y = fread(fid2, 'int16');
% Crossxy(m) = cxy(m-N), m=1, ..., 2N-1
crossxy = xcorr(x(1:800),y(1:800),'biased'); 
len=size(crossxy);                          
% Only half = cxy(m-N), m=1, ...
xy = abs(crossxy(((len-1)/2+1):len));    
% Find max in xy    
[ampxy,posxy]=max(xy);                       

plot(xy),;
xlabel('Lag index, k');
ylabel('Amplitude');

%text(posxy-1,ampxy,...                       
%'\bullet\leftarrow\fontname{times} CorossXY(m) = MAXIMUM',...
%'FontSize',12)

%disp(sprintf('The maximum corssXY(m) found at %d with value =%d \n',...
%    posxy-1,ampxy));

fclose(fid1);
fclose(fid2);



