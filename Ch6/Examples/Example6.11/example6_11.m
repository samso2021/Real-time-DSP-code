%
% example6_11.m - Adaptive channel equalization using 
%                 adaptive FIR filter with LMS algorithm
%

% For the book "Real Time Digital Signal Processing: 
%               Fundamentals, Implementation and Application, 3rd Ed"
%               By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%               Publisher: John Wiley and Sons, Ltd

% define parameters
N = 1024; 
L = 64;                      % Filter order
M = L/2; 
mu = 0.3;                    % Step size
cz = [0.1, 0.3, 0.1];        % Define C(z)
n = [1:N];                   % Time index
sd = 12357; rng(sd);      % Set seed value
% Set seed value using older versions of MATLAB as following
%rand('seed',12357);      % Seed for noise generator 

xn = 2.5*(rand(1,N)-0.5);    % Zero-mean white noise
yn = filter(cz, 1, xn);      % Generate received signal y(n)
dn = [zeros(1,M) xn(1:N-M)]; % d(n)=x(n-M)

h = adaptfilt.lms(L,mu);     % LMS algorithm
[y,e] = filter(h,yn,dn);     % Adaptive filtering
plot(1:N,[e]);               % Plot e(n)
axis([1 N -inf inf]);

xlabel('Time index, n'); 
ylabel('Amplitude');
