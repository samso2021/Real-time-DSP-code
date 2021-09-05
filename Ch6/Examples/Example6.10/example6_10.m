%
% example6_10.m - Adaptive noise cancellation using adaptive
%                 FIR filter with the LMS algorithm
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

% define parameters
Fs = 1000; 
f0 = 110; 
L = 3;
N = 128; 
w0 = 2*pi*f0/Fs;         
pz = [0.1, 0.3, 0.2];     % Define noise path
n = [0:N-1];              % Time index
sd = 12357; rng(sd);      % Set seed value
% Set seed value using older versions of MATLAB as following
%rand('seed',12357);      % Seed for noise generator 
sn = 0.5*sin(w0*n);       % Sine sequence
xn = 2.5*(rand(1,N)-0.5); % Zero-mean white noise
xpn = filter(pz, 1, xn);  % Generate x'(n)
dn = sn+xpn;              % Sinewave embedded in white noise

mu = 0.025;               % Step size mu
h = adaptfilt.lms(L,mu);  % LMS algorithm
[y,e] = filter(h,xn,dn);  % Adaptive filtering
plot(n,sn,':',n,e,'-r');  % Plot s(n) and e(n)
axis([1 N -inf inf]);

xlabel('Time index, n'); 
ylabel('Amplitude');
