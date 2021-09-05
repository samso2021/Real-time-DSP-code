% 
%  Chapter 9 example: Weighting filter
%  File name:	example9_5.m  
%
%  Description: Using LPC coefficients to calculate weighting filter coefficients		 
%
%  For the book "Real Time Digital Signal Processing: 
%                Fundamentals, Implementation and Application, 3rd Ed"
%                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%                Publisher: John Wiley and Sons, Ltd
%
%
%	
clear;
fftL=512;                     % Length of fft for calculate the spectrum
fs=8000;                      % Sampling frequency 
frame=256;                    % LPC frame size
lpcOrder=10;                  % LPC order
start=3192;                   % Start point of the input voice
f=8000*(0:(fftL/2-1))/fftL;   % Frequency scale for display

fil=fopen('voice4.pcm','r');  % Open the pcm data file
b= fread(fil,20000,'short');  % Read 20000 samples to b

w=hamming(frame);             % Generate hamming window
x1=b((start+1):(start+frame));
x=x1.*w;                      % Windowing

y=fft(x,fftL);                % FFT of the specified block
py=10*log10(y.*conj(y)/fftL); % Magnitude
status=fclose(fil);           % Close the file

m=0;                          % Calculation of auto-correstion
while (m<=lpcOrder);
r(m+1)=sum(x((m+1):(frame)).*x(1:frame-m)); 
r(m+1) = r(m+1)/frame; m=m+1;
end;

[a,e]=levinson(r,lpcOrder);   % Levinson

gama_1 = 0.95;
gama_2 = 0.70;
gama_3 = 0.50;

%LEVINSON
a=levinson(r,lpcOrder);

y=fft(a,fftL);
pyy=-10*log10(y.*conj(y));

% Weighting filter with different gama;
a_1 = a*gama_1;a_2 = a*gama_2;a_3 = a*gama_3;
m=0;
while (m<=lpcOrder);
a_1(m+1)=a(m+1)*(gama_1^(m-1)); 
a_2(m+1)=a(m+1)*(gama_2^(m-1));
a_3(m+1)=a(m+1)*(gama_3^(m-1));
m=m+1;
end;

y=fft(a_1,fftL);
pyy_1=-30-pyy-10*log10(y.*conj(y)); % offset 20

y=fft(a_2,fftL);
pyy_2=-50-pyy-10*log10(y.*conj(y)); % offset 20

y=fft(a_3,fftL);
pyy_3=-70-pyy-10*log10(y.*conj(y)); % offset 20

plot(f,pyy(1:(fftL/2)),'-',f,pyy_1(1:(fftL/2)),'-.',f,pyy_2(1:(fftL/2)),'--.',f,pyy_3(1:(fftL/2)),'--');

xlabel('Frequency (Hz)');
ylabel('Magnitude (dB)');
title('A(Z) and W(Z) filter spectrum responses');
h = legend('LPC envelope','\gamma2=0.95&\gamma1=1.0','\gamma2=0.75&\gamma1=1.0','\gamma2=0.50&\gamma1=1.0',4); 

