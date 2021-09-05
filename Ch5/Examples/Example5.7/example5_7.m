%
% example5_7.m - Example of performing circular convolution
%                using DFT
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%

x = [1, 2, 3, 4]; % Define x(n)
h = [1, 0, 1, 1]; % Define h(n)

Xk = fft(x);      % Compute X(k)
Hk = fft(h);      % Compute H(k)
Yk = Xk.*Hk;      % Y(k)=X(k)H(k)
y = ifft(Yk)      % Compute and display circular convolution result

% Linear convolution for comparison of circular convolution
ly = conv(x, h)   % Compute and display linear convolution result
