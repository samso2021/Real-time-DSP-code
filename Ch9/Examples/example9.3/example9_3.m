% 
%  Chapter 9 example: LPC coefficient
%  File name:	example9_3.m 
%
%  Description: Using Leveinson-Durbin algorithm to calculate LPC coefficients		 
%
%  For the book "Real Time Digital Signal Processing: 
%                Fundamentals, Implementation and Application, 3rd Ed"
%                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%                Publisher: John Wiley and Sons, Ltd
%

clear;
fftL=512;                     % Length of fft to calculate the spectrum
fs=8000;                      % Sampling frequency 
frame=256;                    % LPC frame size
p=42;                         % LPC order
start=3192;                   % Start point of the input voice
f=8000*(0:(fftL/2-1))/fftL;   % Frequency scale for display

fid=fopen('voice4.pcm','r');  % Open the pcm data file
b= fread(fid,20000,'int16');  % Read 20000 samples to b

w=hamming(frame);             % Generate hamming window
x1=b((start+1):(start+frame));
x=x1.*w;                      % Windowing

y=fft(x,fftL);                % FFT of the specified block
py=10*log10(y.*conj(y)/fftL); % Magnitude
fclose(fid);                  % Close the file

[a,g] = lpc(x,p)              % LPC function

y=fft(a,fftL);
pyy=10*log10(g)-10*log10(y.*conj(y));
plot(f,pyy(1:(fftL/2)),f,py(1:(fftL/2)));
grid;
xlabel('Frequency (Hz)');
ylabel('Magnitude (dB)');
axis([0 4000 10 80]);
