/* Unscramble Brother scanner model definitions.
 *
 * Decompiled from libsane-brother5.so.1.0.7
 * and modified minimally to make it work.
 *
 * This is unsafe code, don't feed it untrusted input.
 *
 * Wolfgang Frisch <wfrisch@riseup.ent>
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>


typedef uint32_t uint;
typedef int32_t undefined4;
typedef int32_t undefined8;


int scramble_add(int param_1,int param_2)
{
  undefined4 local_c;
  
  local_c = param_2 + param_1;
  if (0x7c < local_c) {
    local_c = local_c + -0x5c;
  }
  if (0x7c < local_c) {
    local_c = local_c + -0x5c;
  }
  if (0x7c < local_c) {
    local_c = local_c + -0x5c;
  }
  if (local_c < 0x20) {
    local_c = local_c + 0x5c;
  }
  if (local_c < 0x20) {
    local_c = local_c + 0x5c;
  }
  if (local_c < 0x20) {
    local_c = local_c + 0x5c;
  }
  return local_c;
}


int scramble_rev(int param_1)
{
  return 0x7c - (param_1 + -0x20);
}


uint scramble_swap1(uint param_1)

{
  uint local_c;
  
  local_c = param_1;
  if (param_1 < 0x7c) {
    if ((param_1 & 1) == 0) {
      local_c = param_1 + 1;
    }
    else {
      local_c = param_1 - 1;
    }
  }
  return local_c;
}


uint scramble_swap2(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint local_c;
  
  uVar1 = param_1;
  if ((0x1f < param_1) && (uVar1 = param_1, param_1 < 0x7c)) {
    uVar2 = param_1 & 3;
    if (uVar2 == 1) {
      uVar1 = param_1 + 1;
    }
    else {
      uVar1 = param_1;
      if (uVar2 != 0) {
        if (uVar2 == 2) {
          uVar1 = param_1 - 1;
        }
        else {
          uVar1 = param_1;
          if (uVar2 != 3) {
            return local_c;
          }
        }
      }
    }
  }
  local_c = uVar1;
  return local_c;
}



uint scramble_swap3(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint local_c;
  
  uVar1 = param_1;
  if ((0x1f < param_1) && (uVar1 = param_1, param_1 < 0x7c)) {
    uVar2 = param_1 & 3;
    if (uVar2 < 3) {
      uVar1 = param_1;
      if (uVar2 == 0) {
        uVar1 = param_1 + 3;
      }
    }
    else {
      uVar1 = local_c;
      if (uVar2 == 3) {
        uVar1 = param_1 - 3;
      }
    }
  }
  local_c = uVar1;
  return local_c;
}


uint scramble_swap4(uint param_1)

{
  uint uVar1;
  uint local_c;
  
  uVar1 = param_1;
  if (param_1 < 0x7c) {
    if ((param_1 & 3) < 2) {
      uVar1 = param_1 + 2;
    }
    else {
      uVar1 = local_c;
      if ((param_1 & 3) < 4) {
        uVar1 = param_1 - 2;
      }
    }
  }
  local_c = uVar1;
  return local_c;
}



uint scramble_swap5(uint param_1)

{
  undefined4 local_c;
  
  local_c = param_1;
  if (param_1 < 0x7c) {
    if ((param_1 & 3) == 0) {
      local_c = param_1 + 2;
    }
    else if ((param_1 & 3) == 2) {
      local_c = param_1 - 2;
    }
  }
  return local_c;
}



uint scramble_swap6(uint param_1)

{
  undefined4 local_c;
  
  local_c = param_1;
  if (param_1 < 0x7c) {
    if ((param_1 & 3) == 1) {
      local_c = param_1 + 2;
    }
    else if ((param_1 & 3) == 3) {
      local_c = param_1 - 2;
    }
  }
  return local_c;
}


int decode_sub(char *input, char *output)
{
  char result_char;
  int32_t k1;
  int32_t k2;
  undefined4 tmp;
  char *out_p;
  char *in_p;
  
  if ((*input == '?') && (input[1] == '#')) {
    k1 = (int)input[2];
    k2 = (int)input[3];
    out_p = output;
    for (in_p = input + 4; *in_p != '\0'; in_p = in_p + 1) {
      if ((*in_p < '|') && ('\x1f' < *in_p)) {
        switch(k1 + k2 & 7) {
        case 0:
          tmp = scramble_swap2((int)*in_p);
          tmp = scramble_rev(tmp);
          result_char = scramble_add(tmp,-3 - k1);
          *out_p = result_char;
          break;
        case 1:
          tmp = scramble_swap1((int)*in_p);
          tmp = scramble_rev(tmp);
          result_char = scramble_add(tmp,-0x14 - k2);
          *out_p = result_char;
          break;
        case 2:
          tmp = scramble_swap6((int)*in_p);
          tmp = scramble_rev(tmp);
          result_char = scramble_add(tmp,-0x45 - k1);
          *out_p = result_char;
          break;
        case 3:
          tmp = scramble_swap4((int)*in_p);
          tmp = scramble_rev(tmp);
          result_char = scramble_add(tmp,-7 - k2);
          *out_p = result_char;
          break;
        case 4:
          tmp = scramble_swap2((int)*in_p);
          tmp = scramble_rev(tmp);
          result_char = scramble_add(tmp,-0x35 - k1);
          *out_p = result_char;
          break;
        case 5:
          tmp = scramble_swap4((int)*in_p);
          tmp = scramble_rev(tmp);
          result_char = scramble_add(tmp,-0x37 - k2);
          *out_p = result_char;
          break;
        case 6:
          tmp = scramble_swap3((int)*in_p);
          tmp = scramble_rev(tmp);
          result_char = scramble_add(tmp,-0x20 - k1);
          *out_p = result_char;
          break;
        case 7:
          tmp = scramble_swap5((int)*in_p);
          tmp = scramble_rev(tmp);
          result_char = scramble_add(tmp,-0x13 - k2);
          *out_p = result_char;
          break;
        default:
          *out_p = *in_p;
                    /* WARNING: Subroutine does not return */
          assert(0);
        }
      }
      else {
        *out_p = *in_p;
      }
      out_p = out_p + 1;
    }
    *out_p = '\0';
  }
  else {
    strcpy(output,input);
  }
  return 0;
}


int decode(char *inp)
{
  size_t inp_len;
  char buf [520];
  
  inp_len = strlen(inp);
  if (inp_len < 0x1f1) {
    decode_sub(inp,buf);
    strcpy(inp,buf);
	return 0;
  }
  else {
	return -1;
  }
}


// not sure if this is necessary but it won't hurt
void dos2unix(char* str) {
	size_t len = strlen(str);
	if (len >= 2) {
		if (str[len-2] == '\r' && str[len-1] == '\n') {
			str[len-2] = '\n';
			str[len-1] = '\0';
		}
	}
}


int main(int argc, char** argv) {

	char* line = NULL;
	size_t len;
	ssize_t nread;

	while ((nread = getline(&line, &len, stdin)) != -1) {
		dos2unix(line);
		decode(line);
		dos2unix(line);
		fwrite(line, strlen(line), 1, stdout);
	}
	return 0;
}
