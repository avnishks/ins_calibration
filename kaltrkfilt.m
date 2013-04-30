function [sys,x0,str,ts]=kaltrkfilt(t,x,u,flag,dt,q,r,p11,p22,p33)
%Kalman tracking filter.

   y = zeros(6,1);

switch flag

  %%%%%%%%%%%%%%%%%%
  % Initialization %
  %%%%%%%%%%%%%%%%%%
  case 0         
    [sys,x0,str,ts] = mdlInitializeSizes(dt,p11,p22,p33);

  %%%%%%%%%%%%%%%%%%%%%%%%
  % Others  &  Terminate %
  %%%%%%%%%%%%%%%%%%%%%%%%
  case {1,9}
    sys = []; % do nothing

  %%%%%%%%%%%%%%%
  % Update      %
  %%%%%%%%%%%%%%%
  case 2
    sys = mdlUpdate(t,x,u,dt,q,r);

  %%%%%%%%%%
  % Output %
  %%%%%%%%%%  
  case 3
    sys = mdlOutputs(t,x,u); 
    
  %%%%%%%%%%%%%%%
  % Update      %
  %%%%%%%%%%%%%%%
  case 4
    sys = mdlGetTimeofNextVarHit(t,x,u,dt);
 
  otherwise
    error(['unhandled flag = ',num2str(flag)]);
    
end

% end kaltrkfilt
%
%=============================================================================
% mdlInitializeSizes
% Return the sizes, initial conditions, and sample times for the S-function.
%=============================================================================
%
function [sys,x0,str,ts] = mdlInitializeSizes(dt,p11,p22,p33)
%
   sizes = simsizes;
   sizes.NumContStates  = 0;
   sizes.NumDiscStates  = 9;
   sizes.NumOutputs     = 6;
   sizes.NumInputs      = 1;
   sizes.DirFeedthrough = 0;
   sizes.NumSampleTimes = 1;

   sys = simsizes(sizes);
   str = [];
   x0 = 0.0;
   x0(4) = p11;
   x0(7) = p22;
   x0(9) = p33;
   ts  = [dt 0];   % sample time: [period, offset]

% end mdlInitializeSizes
%
%=============================================================================
% mdlUpdate
% Compute updates for discrete states.
%=============================================================================
%
function sys = mdlUpdate(t,x,u,dt,q,r)
%
% x vector mapping to MATLAB states
%   x1 through x3 are the same
%
% P matrix mapping to MATLAB states
%   [p11  p12  p13]   [ x4 x5 x6 ]
%   [ -   p22  p23] = [  - x7 x8 ]
%   [ -    -   p33]   [  -  - x9 ]

% state time update
   tux1 = x(1) + x(2)*dt;
   tux2 =        x(2) + x(3)*dt;
   tux3 =               x(3);

%   
%   
%   
% covariance time updte   
   tux4 = x(4) + 2.0*dt*x(5)           + dt^2*x(7);
   tux5 =               x(5) + dt*x(6) + dt  *x(7)    + dt^2   *x(8);
   tux6 =                         x(6)                + dt     *x(8);
   tux7 =                                     x(7)    + 2.0*dt *x(8) + dt^2*x(9);
   tux8 =                                                       x(8) +   dt*x(9);
   tux9 =                                                                   x(9) + dt*q;
%
   x(1) = tux1;
   x(2) = tux2;
   x(3) = tux3;
%
   x(4) = tux4;
   x(5) = tux5;
   x(6) = tux6;
   x(7) = tux7;
   x(8) = tux8;
   x(9) = tux9;

% measurement variance
      a = tux4 + r ;
%       if abs(a) < 1e-15
%           a = a + 1e-6
%           'Oh'
%       end
%
% state measurement update
      mux1 = tux1 + (tux4/a)*(u-tux1);
      mux2 = tux2 + (tux5/a)*(u-tux1);
      mux3 = tux3 + (tux6/a)*(u-tux1);
%   
% covariance measurement udpate
      mux4 = (1.0 - (tux4/a))*tux4;
      mux5 = (1.0 - (tux4/a))*tux5;
      mux6 = (1.0 - (tux4/a))*tux6;
      mux7 = tux7 - (tux5/a)*tux5;
      mux8 = tux8 - (tux5/a)*tux6;
      mux9 = tux9 - (tux6/a)*tux6;
%
      x(1) = mux1;
      x(2) = mux2;
      x(3) = mux3;
%
      x(4) = mux4;
      x(5) = mux5;
      x(6) = mux6;
      x(7) = mux7;
      x(8) = mux8;
      x(9) = mux9;
%   
   sys = x;

% end mdlUpdate
%
%=============================================================================
% mdlOutputs
% Return the output vector for the S-function
%=============================================================================
%
function sys = mdlOutputs(t,x,u)
%
   y(1) = x(1);
   y(2) = x(1)+sqrt(x(4));
   y(3) = x(1)-sqrt(x(4));
   y(4) = x(2);
   y(5) = x(2)+sqrt(x(7));
   y(6) = x(2)-sqrt(x(7));
%   
   sys = y;

% end mdlOutputs
%=============================================================================
% mdlGetTimeofNextVarHit
%=============================================================================
function sys = mdlGetTimeofNextVarHit(t,x,u,dt)
%
   sys = t + dt;

% end mdlGetTimeofNextVarHit