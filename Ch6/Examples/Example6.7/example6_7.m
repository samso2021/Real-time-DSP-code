%
% example6_7.m - Adaptive identification of given FIR filter
%                using adaptive FIR filter with LMS algorithm
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

clear all;
sd = 12357; rng(sd);         % Set seed value
x  = randn(1,128);           % Reference signal x(n)
b  = [0.1,0.2,0.4,0.2,0.1];  % An FIR filter to be identified
d  = filter(b,1,x);          % Desired signal d(n)
mu = 0.05;                   % Step size mu
h = adaptfilt.lms(5,mu);     % LMS algorithm
[y,e] = filter(h,x,d);       % Adaptive filtering
n = 1:128;
plot(n,d,'-',n,y,':',n,e,'x--'); 
axis([1 128 -inf inf]);
xlabel('Time index, n'); 
ylabel('Amplitude');
