%
% example5_8.m - Computation of linear convolution using
%                DFT and zero padding
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd
%

x = [1, 2, 3, 4]; % Define x(n)
h = [1, 0, 1, 1]; % Define h(n)
y = conv(x, h)    % Linear convolution in time domain

xz = [1, 2, 3, 4, zeros(1, 4)]; % Zero padding
hz = [1, 0, 1, 1, zeros(1, 4)]; % Zero padding
Xk = fft(xz);   % DFT of zero-padded x(n)
Hk = fft(hz);   % DFT of zero-padded h(n)
Yk = Xk.*Hk;    % Multiplication in frequency domain
y = ifft(Yk)    % Circular convolution of zero-padded sequences