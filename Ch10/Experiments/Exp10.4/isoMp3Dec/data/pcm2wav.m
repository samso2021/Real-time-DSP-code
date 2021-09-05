% 
%  pcm2wav.m - MATLAB scrip for Experiment EXP10.4 MP3 decoder
%
%  Description: Convert ISO MP3 decoder PCM output to WAV format
%				 
%
%  For the book "Real Time Digital Signal Processing: 
%                Fundamentals, Implementation and Application, 3rd Ed"
%                By Sen M. Kuo, Bob H. Lee, and Wenshun Tian
%                Publisher: John Wiley and Sons, Ltd
%

fid1=fopen('musicD_44p1_128bps.mp3.dec', 'rb', 'ieee-be');
x = fread(fid1,'short');
fclose(fid1);
n=length(x);
y=zeros(n/2, 2);
i=1;
for k=1:2:n
	y(i,1)=x(k);
	y(i,2)=x(k+1);
	i = i+1;
end
y = y/32768;   
Fs = 44100;                            % Sampling frequency
nbit=16;                               % Number of bits/sample
wavwrite(y,Fs,nbit,'decodedMP3Audio'); % Write stereo WAV file
sound(y,Fs,nbit);