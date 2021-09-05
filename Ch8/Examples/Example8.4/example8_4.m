%
% example8_4.m - MATLAB code for Example 8.4
%
% Impulse response of room transfer function
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%

clear;
fid1 = fopen('roomImp.pcm','rb');
h = fread(fid1,30000,'short');

plot(h(1:30000)),  title('Room impulse response');
axis([1 30000 -5000 5000]);
xlabel('Time index, n'), ylabel('Amplitude');
fclose(fid1)

